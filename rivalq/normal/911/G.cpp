// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5;

int t[4*N][101];


void update(int v,int tl,int tr,int i,int x,int y){
        if(tl == tr){
             t[v][x] = y;
             return;   
        }else{
                int mid = (tl  + tr)/2;
                if(i <= mid)update(2*v,tl,mid,i,x,y);
                else update(2*v+1,mid+1,tr,i,x,y);
                for(int i = 1; i <= 100; i++){
                        t[v][i] = t[2*v+1][t[2*v][i]];
                }
        }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n; cin >> n;
    vector<int>a(n+1);
    
    for(int i = 1; i <= n; i++){
            cin >> a[i];
    }
    for(int i = 1; i < 4*N ; i++){
            for(int j = 1; j <= 100; j++){
                 t[i][j] = j;
            }
    }

    int q; cin >> q;
    vector<array<int,3>>vec[n + 2];
    for(int i = 0; i < q; i++){
                int l,r,x,y; cin >> l >> r >> x >> y;;
                vec[l].push_back({i,x,y});
                vec[r + 1].push_back({i,x,x});
    }

    for(int i = 1; i <= n; i++){
                for(auto j:vec[i]){
                        update(1,0,q,j[0],j[1],j[2]);
                }
                cout << t[1][a[i]] << " ";
     }    


    return 0;
}