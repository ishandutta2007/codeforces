#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 62 * 62;
int n;
char s[N][4];
char str[N];
int pre[M] , mcnt;
struct edge {
    int x , next;
}e[N];
int f[M] , id[M] , od[M];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}
int ID(char c) {
    if (islower(c))
        return c - 'a';
    if (isupper(c))
        return c - 'A' + 26;
    if (isdigit(c))
        return c - '0' + 52;
    return -1;
}
bool u[N];
vector<char> res;
void dfs(int x) {
    for (int& i = pre[x] ; ~i ;) {
        int y = e[i].x;
        char c = s[i][2];
        i = e[i].next;
        dfs(y);
        res.push_back(c);
    }
}

void work() {
    int i , x , y;
    vector<int> v;
    scanf("%d",&n);
    for (i = 0 ; i < M ; ++ i) f[i] = i , pre[i] = -1;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        strcpy(s[i] , str);
        x = ID(str[0]) * 62 + ID(str[1]);
        y = ID(str[1]) * 62 + ID(str[2]);
        v.push_back(x);
        v.push_back(y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        ++ od[x] , ++ id[y];
        f[getf(x)] = getf(y);
    }
    x = v.back();
    for (auto y : v)
        if (getf(y) != getf(x)) {
            puts("NO");
            return;
        }
    vector< pair<int , int> > Node;
    for (i = 0 ; i < M ; ++ i)
        if (id[i] != od[i])
            Node.push_back(make_pair(id[i] - od[i] , i));
    sort(Node.begin() , Node.end());
    if (Node.size() != 2 && Node.size() != 0) {
        puts("NO");
        return;
    }
    if (Node.size() == 0) {
        for (i = 0 ; i < M ; ++ i)
            if (od[i])
                break;
        x = i;
    } else {
        if (Node[0].first != -1) {
            puts("NO");
            return;
        }
        x = Node[0].second;
    }
    puts("YES");
    i = x / 62;
    if (i < 26) putchar('a' + i);
    else if (i < 52) putchar('A' - 26 + i);
    else putchar('0' + i - 52);
    i = x % 62;
    if (i < 26) putchar('a' + i);
    else if (i < 52) putchar('A' - 26 + i);
    else putchar('0' + i - 52);
    dfs(x);
    reverse(res.begin() , res.end());
    for (auto c : res)
        printf("%c" , c);
    puts("");
}

int main()
{
    work();
    return 0;
}