#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

// here we supposed that the size of alphabet
// fits constraints [1..256]

template < int Alph >
struct SuffixTree
{
    // 0 - fictive vertex
    // 1 - root
    
    enum
    {
        PRE_ROOT = 0,
        ROOT = 1,
        EMPTY = 0,
    };

    struct List
    {
        size_t start_pos; // 0 - based index
        size_t end_pos;   // [start_pos, end_pos)
                       // when end_pos == (size_t) -1, int refers to list
        int parent;
        int suf_link; // valid only to inner vertices,
                      // when invalid, refers to -1-th vertex
        int next[Alph]; // pointers to marked children

        void
        set_value(int val)
        {
            std::fill(next, next + Alph, val);
        }

        void
        clear()
        {
            set_value(EMPTY);
        }

        List()
        {
            start_pos = 0;
            end_pos = 0;
            parent = -1;
            suf_link = -1;
            clear();
        }
    };

    struct ActiveNode
    {
        int go; // vertex, what you go to
        int processed; // number of symbols read on parent's edge
        ActiveNode() : go(0), processed(0)
        {}
    };

    std::vector < int > str;
    std::vector < List > __tree;
    std::vector < int > cnt[3];
    size_t size;
    size_t str_len;
    ActiveNode active_node_pos;

    int
    edge_len(const int x) const
    {
        return std::min(__tree[x].end_pos, str_len) - __tree[x].start_pos;
    }

    void
    inc_size()
    {
        ++size;
        if (__tree.size() == size) {
            __tree.push_back(List());
        }
    }

    bool can_go(const ActiveNode &, int);
    void go(ActiveNode &, int);
    void cut_edge(ActiveNode &);
    void add_leaf(int, int);
    void make_suf_link(int);
    void add_elem(int);
    void init();
    SuffixTree(); 
    ~SuffixTree();
    SuffixTree(const char *, int = -1);
    void output_data();
};

template < int Alph >
bool
SuffixTree< Alph >::can_go(
        const SuffixTree< Alph >::ActiveNode &pos,
        int next_char)
{
    int next_vertex = pos.go;
    int distance_to_go = pos.processed;
    if (distance_to_go == edge_len(next_vertex)) {
        return (__tree[next_vertex].next[next_char] != EMPTY);
    }
    return (str[__tree[next_vertex].start_pos + distance_to_go] == next_char);
}

template < int Alph >
void
SuffixTree< Alph >::go(
        SuffixTree< Alph >::ActiveNode &pos, 
        int next_char)
{
    if (pos.processed == edge_len(pos.go)) {
        pos.go = __tree[pos.go].next[next_char];
        pos.processed = 1;
    } else {
        ++pos.processed;
    }
}

template < int Alph >
void
SuffixTree< Alph >::cut_edge(SuffixTree< Alph >::ActiveNode &pos)
{
    inc_size();
    __tree[size].start_pos = __tree[pos.go].start_pos;
    __tree[size].end_pos = __tree[pos.go].start_pos + pos.processed;
    __tree[size].parent = __tree[pos.go].parent;
    __tree[size].clear();
    int left_border = __tree[size].start_pos;
    __tree[__tree[size].parent].next[str[left_border]] = size;
    left_border = __tree[size].end_pos;
    __tree[size].next[str[left_border]] = pos.go;
    __tree[pos.go].start_pos = left_border;
    __tree[pos.go].parent = size;
    pos.go = size;
    pos.processed = edge_len(size);
}

template < int Alph >
void
SuffixTree< Alph >::add_leaf(int cur_ver, int next_char)
{
    inc_size();
    __tree[size].start_pos = str_len - 1;
    __tree[size].end_pos = size_t(-1);
    __tree[size].parent = cur_ver;
    __tree[size].clear();
    __tree[cur_ver].next[next_char] = size;
}

template < int Alph >
void
SuffixTree< Alph >::make_suf_link(int cur_ver)
{   /* considering case cur_ver == ROOT separately,
     * because otherwise pos == -1, and this leads to invalid ranges
     * and invalid memory reading
     */
    if (cur_ver == ROOT) {
        return;
    }
    int tmp_ver = __tree[__tree[cur_ver].parent].suf_link;
    int distance = edge_len(cur_ver);
    int pos = str_len - 1 - distance;
    int stage_distance = edge_len(__tree[tmp_ver].next[str[pos]]);
    // condition: distance >= 0 always
    while (distance >= stage_distance && distance) {
        tmp_ver = __tree[tmp_ver].next[str[pos]];
        pos += stage_distance;
        distance -= stage_distance;
        if (distance) {
            stage_distance = edge_len(__tree[tmp_ver].next[str[pos]]);
        }
    }
    if (!distance) {
        __tree[cur_ver].suf_link = tmp_ver;
    } else {
        ActiveNode a_node_pos;
        a_node_pos.go = __tree[tmp_ver].next[str[pos]];
        a_node_pos.processed = distance;
        cut_edge(a_node_pos);
        __tree[cur_ver].suf_link = a_node_pos.go;
    }
}

template < int Alph >
void
SuffixTree< Alph >::add_elem(int next_char)
{
    ++str_len;
    str.push_back(next_char);
    while (!can_go(active_node_pos, next_char)) {
        if (active_node_pos.processed != edge_len(active_node_pos.go)) {
            cut_edge(active_node_pos);
        }
        int cur_ver = active_node_pos.go;
        add_leaf(cur_ver, next_char);
        make_suf_link(cur_ver);
        active_node_pos.go = __tree[cur_ver].suf_link;
        active_node_pos.processed = edge_len(active_node_pos.go);
    }
    go(active_node_pos, next_char);
}

template < int Alph >
void
SuffixTree< Alph >::init()
{
    str_len = 0;
    size = 0;
    __tree.push_back(List());
    inc_size();
    __tree[ROOT].start_pos = -1;
    active_node_pos.go = ROOT;
    active_node_pos.processed = 1;
    __tree[PRE_ROOT].set_value(ROOT);
    __tree[ROOT].parent = PRE_ROOT;
    __tree[ROOT].suf_link = PRE_ROOT;
    __tree[PRE_ROOT].suf_link = PRE_ROOT;
}

template < int Alph >
SuffixTree< Alph >::SuffixTree()
{
    init();
}

template < int Alph >
SuffixTree< Alph >::SuffixTree(const char *str, int maxnum)
{
    init();
    for (; *str && maxnum; ++str, --maxnum) {
        add_elem(*str - 'a' + 3);
    }
}

template < int Alph >
SuffixTree< Alph >::~SuffixTree()
{}

template < int Alph >
void
SuffixTree< Alph >::output_data()
{
    for (int i = 1; i < int(str.size()); ++i) {
        std::cout << str[i];
    }
    std::cout << '\n';
    std::cout << size << ' ' << (size - 1) << '\n';
    for (size_t i = 2; i <= size; ++i) {
        std::cout << __tree[i].parent << ' ' << i << ' ' 
            << __tree[i].start_pos << ' ' << (std::min(__tree[i].end_pos, str_len) - 1) << ' ';
        for (size_t it = __tree[i].start_pos; it < std::min(__tree[i].end_pos, str_len); ++it) {
            std::cout << char(str[it] + 'a' - 3);
        }
        std::cout << '\n';
    }
    std::cout << "active node = " << active_node_pos.go << ", " <<
        active_node_pos.processed << '\n';
}

typedef long long ll;

typedef SuffixTree< 29 > ST;
typedef ST::ActiveNode AT;

typedef pair< int, int > pii;

const int MAXN = 300500;
const int MD = 1000000007;

char s[MAXN];
vector< pair< int, int > > strs;
int add[1111111];
int curk;
int lens[3];

void
addVal(int &dst, int src)
{
    dst += src;
    if (dst >= MD) {
        dst -= MD;
    }
}

void
pushV(int v)
{
    addVal(add[v * 2], add[v]);
    addVal(add[v * 2 + 1], add[v]);
    add[v] = 0;
}

void
addSeg(int from, int to, int l1, int r1, int v, int inc)
{
    if (max(from, l1) <= min(to, r1)) {
        if (from <= l1 && to >= r1) {
            addVal(add[v], inc);
        } else {
            pushV(v);
            addSeg(from, to, l1, (l1 + r1) / 2, v * 2, inc);
            addSeg(from, to, (l1 + r1) / 2 + 1, r1, v * 2 + 1, inc);
        }
    }
}

void
markCnt(ST &t, int pos, int lenStr)
{
    bool isLeaf = true;
    t.cnt[0][pos] = t.cnt[1][pos] = t.cnt[2][pos] = 0;
    for (int i = 0; i < 29; ++i) {
        int next_v = t.__tree[pos].next[i];
        if (next_v) {
            isLeaf = false;
            markCnt(t, next_v, lenStr + t.edge_len(next_v));
            for (int j = 0; j < 3; ++j) {
                t.cnt[j][pos] += t.cnt[j][next_v];
            }
        }
    }
    if (isLeaf) {
        int getLastChar = 0;
        if (lenStr <= lens[2]) {
            getLastChar = 2;
        } else if (lenStr <= lens[1] + lens[2]) {
            getLastChar = 1;
        } else {
            getLastChar = 0;
        }
        t.cnt[getLastChar][pos]++;
    }
    /*cerr << "for node = " << pos << " cnt: ";
    for (int i = 0; i < 3; ++i) {
        cerr << t.cnt[i][pos] << " ";
    }
    cerr << endl;*/
}

void
run(const ST &tree, int node, int lenStr)
{
    if (node != 1) {
        int mult = 1ll;
        for (int i = 0; i < 3; ++i) {
            mult = 1ll * mult * tree.cnt[i][node] % MD;
        }
        int minLen = tree.edge_len(node);
        addSeg(lenStr - minLen + 1, lenStr, 1, curk, 1, mult);
    }
    for (int i = 0; i < 29; ++i) {
        int next_v = tree.__tree[node].next[i];
        if (next_v) {
            run(tree, next_v, lenStr + tree.edge_len(next_v));
        }
    }
}

int
main()
{
    char *curPnt = s;
    int minV = MAXN;
    for (int i = 0; i < 3; ++i) {
        scanf(" %s", curPnt);
        int curLen = 0;
        while (*curPnt) {
            curPnt++;
            curLen++;
        }
        lens[i] = curLen + 1;
        minV = min(minV, curLen);
        *curPnt = 'a' - 3 + i;
        curPnt++;
    }
    int len = strlen(s);
    curk = 2;
    while (curk < len) curk *= 2;
    for (int i = 0; i < 2 * curk; ++i) {
        add[i] = 0;
    }
    ST tree(s, len + 1);
    //tree.output_data();
    for (int i = 0; i < 3; ++i) {
        tree.cnt[i].assign(2 * tree.__tree.size(), 0);
    }
    markCnt(tree, 1, 0);
    run(tree, 1, 0);
    for (int i = 1; i < curk; ++i) {
        pushV(i);
    }
    for (int i = 1; i <= minV; ++i) {
        printf("%d ", add[i + curk - 1]);
    }
    printf("\n");
    return 0;
}