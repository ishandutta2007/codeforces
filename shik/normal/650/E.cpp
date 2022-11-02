// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int MAXN = 1500010;
struct Node {
	Node *ch[2], *p; int size, val, mx;
	bool rev;
	Node(int t = 0);
	inline bool dir(void) {return p->ch[1] == this;}
	inline void SetC(Node *x, bool d) {
		ch[d] = x; x->p = this;
	}
	inline void Rev(void) {
		swap(ch[0], ch[1]); rev ^= 1;
	}
	inline void Push(void) { 
		if (rev) {
			ch[0]->Rev();
			ch[1]->Rev();
			rev = 0;
		}
	}
	inline void Update(void) { 
		size = ch[0]->size + ch[1]->size + 1;
        mx = max(val, max(ch[0]->mx, ch[1]->mx));
	}
}Tnull, *null = &Tnull, *fim[MAXN];
// null
Node::Node(int _value){ch[0] = ch[1] = p = null; rev = 0; mx = val = _value;}
inline bool isRoot(Node *x) {return x->p == null || (x != x->p->ch[0] && x != x->p->ch[1]);}
inline void rotate(Node *x) {
	Node *p = x->p; bool d = x->dir();
	p->Push(); x->Push();
	if (!isRoot(p)) p->p->SetC(x, p->dir()); else x->p = p->p;
	p->SetC(x->ch[!d], d);
	x->SetC(p, !d);
	p->Update();
}
inline void splay(Node *x) {
	x->Push();
	while (!isRoot(x)) {
		if (isRoot(x->p)) rotate(x);
		else {
			if (x->dir() == x->p->dir()) {rotate(x->p); rotate(x);} 
			else {rotate(x); rotate(x);}
		}
	}
	x->Update();
}
inline Node* Access(Node *x) {
	Node *t = x, *q = null;
	for (; x != null; x = x->p) {
		splay(x); x->ch[1] = q; q = x;
	}
	splay(t); //info will be updated in the splay;
	return q;
}
inline void Evert(Node *x) {
	Access(x); x->Rev();
}
inline void link(Node *x, Node *y) {
	Evert(x); x->p = y;
}
inline Node* getRoot(Node *x) {
	Node *tmp = x;
	Access(x);
	while (tmp->Push(), tmp->ch[0] != null) tmp = tmp->ch[0];
	splay(tmp);
	return tmp;
}
// xy
inline void cut(Node *x, Node *y) { 	
	Access(x); splay(y);
	if (y->p != x) swap(x, y);
	Access(x); splay(y);
	y->p = null;
}
inline Node* getPath(Node *x, Node *y) {
	Evert(x);
    Access(y);
	return y;
}
inline void clear(void) {
	null->rev = 0; null->size = 0; null->mx = null->val = 0;
}

int n;
vector<PII> e1,e2;
int main() {
    R(n);
    REP(i,n-1) {
        int a,b;
        R(a,b);
        if ( a>b ) swap(a,b);
        e1.PB(MP(a,b));
    }
    REP(i,n-1) {
        int a,b;
        R(a,b);
        if ( a>b ) swap(a,b);
        e2.PB(MP(a,b));
    }
    sort(ALL(e1));
    sort(ALL(e2));
    clear();
    REP1(i,1,n) fim[i]=new Node(0);
    REP1(i,1,n-1) {
        if ( binary_search(ALL(e2),e1[i-1]) ) fim[n+i]=new Node(0);
        else fim[n+i]=new Node(i);
    }
    REP(i,n-1) {
        int a=e1[i].first;
        int b=e1[i].second;
        link(fim[a],fim[n+i+1]);
        link(fim[b],fim[n+i+1]);
    }
    
    vector<pair<PII,PII>> sol;
    int id=n+n;
    for ( auto i:e2 ) {
        if ( binary_search(ALL(e1),i) ) continue;
        int a=i.first;
        int b=i.second;
        auto p=getPath(fim[a],fim[b]);
        int mx=p->mx;
        assert(mx!=0);
        int x=e1[mx-1].first;
        int y=e1[mx-1].second;
        cut(fim[x],fim[n+mx]);
        cut(fim[y],fim[n+mx]);
        id++;
        fim[id]=new Node(0);
        link(fim[a],fim[id]);
        link(fim[b],fim[id]);
        sol.PB(MP(MP(x,y),MP(a,b)));
    }
    W(SZ(sol));
    for ( auto i:sol ) W(i.first.first,i.first.second,i.second.first,i.second.second);
    return 0;
}