#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 400007

// https://github.com/radoslav11/Coding-Library/blob/master/strings/suffix_automaton.cpp
struct suffix_automaton
{
	map<char, int> to[MAXN];
	int len[MAXN], link[MAXN];
	int last, psz = 0;

    int cnt[ MAXN ] ;
    
	void add_letter(char c, int coef)
	{
		int p = last, cl, q;
		if(to[p].count(c))
		{
  			q = to[p][c];
			if(len[q] == len[p] + 1)
			{
				last = q;
				return;
			}

			cl = psz++;
			len[cl] = len[p] + 1;
			to[cl] = to[q];
			link[cl] = link[q];
			link[q] = cl;
			last = cl;
	
			for(; to[p][c] == q; p = link[p])
				to[p][c] = cl;
			
			return;
		}

		last = psz++;
		len[last] = len[p] + 1;
        
        cnt[ last ] = coef ^ 1 ;
        
		for(; to[p][c] == 0; p = link[p])
			to[p][c] = last;
	
		if(to[p][c] == last) 
		{
			link[last] = p;
			return;
		}

		q = to[p][c];
		if(len[q] == len[p] + 1)
		{
			link[last] = q;
			return;
		}

		cl = psz++;
		len[cl] = len[p] + 1;
		to[cl] = to[q];
		link[cl] = link[q];
		link[q] = cl;
		link[last] = cl;

		for(; to[p][c] == q; p = link[p])
			to[p][c] = cl;

	}

	void clear()
	{
		for(int i = 0; i < psz; i++)
			len[i] = 0, link[i] = 0, to[i].clear();
		psz = 1;
		last = 0;
	}

	void init(string a, string s)
	{
		clear();
		for(int i = 0; i < (int)a.size(); i++)
			add_letter(a[i], ( s[ i ] - '0' ) );
	}
	
	suffix_automaton() {psz = 0; clear();}

    vector < int > v[ MAXN ] ;

    void setup ( ) {
        for ( int i = 1 ; i < psz ; ++ i ) {
            v[ link[ i ] ].push_back ( i ) ;
        }
    }
    void dfs ( int vertex ) {
        for ( auto x : v[ vertex ] ) {
            dfs ( x ) ;
            cnt[ vertex ] += cnt[ x ] ;
        }
    }
};

suffix_automaton w ;


int n ;
string a ;
string s ;

void input ( ) {
    cin >> n ;
    cin >> a >> s ;
    w.init ( a , s ) ;
}


void solve ( ) {
    w.setup ( ) ;
    w.dfs ( 0 ) ;
    long long ans = 0 ;
    for ( int i = 0 ; i < w.psz ; ++ i ) {
        long long aux = 1LL * w.len[ i ] * w.cnt[ i ] ;
        ans = max ( ans , aux ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}