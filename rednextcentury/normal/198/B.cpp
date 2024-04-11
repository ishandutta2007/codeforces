#include <bits/stdc++.h>
#define ii pair<bool,int>
#define s second
#define f first
#define OO 1e9
#define disout for(int i=0 ; i <= n+k ; i++)cout << dist[0][i] << ' ';cout<<endl;for(int i=0 ; i <= n+k ; i++)cout << dist[1][i] << ' ';cout << endl;

using namespace std;

const int N = 3e5 + 500;
bool Grid[2][N];
int  dist[2][N];
queue< ii >q;
string L ,R;
int n ,k;


int main()
{
    /* 1 = X  | 0 = - */
    /* 1 = R  | 0 = L */

    cin >> n >> k;
    cin >> L >> R;

    for(int i=0 ; i <= n+k ; i++){
        if( i < n ){
            Grid[0][i] = ( L[i] == 'X' );
            Grid[1][i] = ( R[i] == 'X' );
        }
        dist[0][i] = dist[1][i] = OO;
    }   dist[0][0] = 0;

    q.push( {0,0} );
    int water = 0;
    while( !q.empty() ){
        ii u = q.front();
        q.pop();
        water = dist[u.f][u.s]+1;
        if( u.s-1 >= 0 && u.s-1 >= water){
            if( !Grid[u.f][u.s-1] && dist[u.f][u.s-1] == OO){
                dist[u.f][u.s-1] = dist[u.f][u.s] + 1;
                q.push( {u.f ,u.s-1 } );
            }
        }
        if( u.s+1 >= 0 ){
            if( !Grid[u.f][u.s+1] && dist[u.f][u.s+1] == OO){
                dist[u.f][u.s+1] = dist[u.f][u.s] + 1;
                q.push( {u.f ,u.s+1 } );
            }
        }
        if( u.s + k >= 0 ){
            if(u.s + k >= n){cout << "YES" << endl;exit(0);}
            if( !Grid[!u.f][u.s+k] && dist[!u.f][u.s+k] == OO){
                dist[!u.f][u.s+k] = dist[u.f][u.s] + 1;
                q.push( {!u.f ,u.s+k } );
            }
        }
        water ++;
        if(u.s >= n) break;
    }

    //disout
    bool flag = false;
    for(int i=n-1 ; i <= n+k ; i++){
        if( dist[0][i] != OO || dist[1][i] != OO ){
            flag = true;
            break;
        }
    }

    flag ? puts("YES") : puts("NO");

    return 0;
}