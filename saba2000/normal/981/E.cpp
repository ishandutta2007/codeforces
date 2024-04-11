#include<bits/stdc++.h>
#define ll long long
#define S 100
using namespace std;
bitset<10009> B[109];
vector<int> V[10009];
bitset<10009> an;
vector<int> ans;
int n,q;
main(){
    cin>>n>>q;
    for(int i= 0; i <= S; i++)
        B[i] = 1;
    an = 1;
    for(int i = 0; i < q; i++){
        int l, r, k;
        cin>>l>>r>>k;
        for(int i = l/S + 1; i < r/S; i++)
            B[i] = (B[i] | (B[i] << k));
        for(int i = l; (((i == l || i%S) && i <= r)); i++){
            V[i].push_back(k);
        }
        if(l / S != r/S)
        for(int i = max(l,r - r % S); i <= r; i++)
             V[i].push_back(k);
    }
    for(int i = 1; i <= n; i++){
        bitset<10009> b = B[i/S];
        for(int j = 0; j < V[i].size(); j++)
            b |= (b << V[i][j]);
        an|=b;
    }
    for(int i = 1; i <= n; i++)
        if(an[i]) ans.push_back(i);
        cout<<ans.size()<<endl;
    for(int i =0 ; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}