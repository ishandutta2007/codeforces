#include<bits/stdc++.h>
using namespace std;
long long M =10004205361450474;
long long P;
long long T = 0;
long long ask(vector<long long> v){
   cout<<v.size()<<endl;
    for(long long i = 0; i< v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
//cout<<++T<<endl;
    fflush(stdout);
    long long k = -1;
    /*if(P < v[0]) k = 0;
        else if(P > v.back()) k = v.size();
    else for(long long i = 0; i < v.size() - 1; i++)
        if(P > v[i] && P < v[i+1]) k = i+1;
    else if(P == v[i] || P == v[i+1]) k = -1;*/
    cin >> k;
    //cout<<k<<endl<<endl<<endl;
    if(k <= -1) exit(0);
    return k;
}
void solve(long long k, long long l, long long r){
     k = min(l,(long long) 10000);

//cout<<k<<" "<<l<<" "<<r<<endl;
    vector<long long> V;
    if(r - l + 1 <= k){
    for(long long i = l; i <= r; i++)
        {V.push_back(i);} ask(V); return;}
long long LL = l;
    if(k < 10000 && r >1e9 )  V.push_back(20468427), l = 20468428, k --;
else if(k < 10000) V.push_back(4094), V.push_back(8190),
    V.push_back(16382),l = 16383, k-=3;
    long long R = (r - l + 1 - k);
    long long A = R / (k + 1);
    long long B = R % (k + 1);
    long long C = (k + 1) - B;
        long long x = l;
        if(R <= 0)
           for(long long i = l; i <= r; i++)
        V.push_back(i);
        else{
        while(C --)
            if(C + B == 0) break; else
            V.push_back(x + A),
            x += A + 1;
        while(B --)
            if(B == 0) break; else
            V.push_back(x + A + 1),
            x += A + 2;
        }
     x = ask(V);
    if(x == 0){
        solve(k, LL, V[0] - 1);
    }
    else
    if(x == V.size())
        solve(k, V.back()+1, r);
    else solve(k, V[x-1] + 1, V[x] - 1);
}
main(){
    long long Z =204761410474;
   // cin>>P;
    long long x = ask({Z});
    if(x == 0){
        x = ask({2046});
        if(x == 0){
            long long x =ask({6});
            if(x == 0){
                long long x = ask({2});
                if( x == 0) ask({1});
                else
                ask({3,4,5});
            }
            else{
                vector<long long> v ={14,30,62,126,254,510,1022};
                long long x = ask(v);
                if(x == 0) solve(7,7,13);
                if(x == v.size()) solve(1023,1023,2045);
                solve(v[x-1]+1,v[x-1]+1,v[x]-1);
            }
        }
        else solve(2047, 2047, Z-1);
    }
    else solve(10000, Z+1, M);
}