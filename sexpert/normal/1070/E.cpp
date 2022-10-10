#include <bits/stdc++.h>
using namespace std;

bool ok=false;
int arr[1000005];
long long int n, m, t;

int check(int d){
    ok=false;
    long long int cont=0;
    long long int tiempototal=0;
    long long int tiempoparcial=0;
    long long int res=0;
    for(int i=0;i<n;i++){
        if(cont==m){
            tiempototal+=tiempoparcial;
            tiempoparcial=0;
            cont=0;
        }
        if(arr[i]<=d){
            if(tiempototal+arr[i]>t){
                return res;
            }
            cont++;
            tiempototal+=arr[i];
            tiempoparcial+=arr[i];
            res++;
        }
    }
    ok=true;
    return res;
}


int main(void){

    int c;
    cin>>c;
    while(c--){
        //int n, m, t;
        cin>>n>>m>>t;
        //int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        //for(int i=0;i<n;i++) arr[i]*=2;
        long long int hi = min(t, 200000ll);
        long long int lo=1;
        long long int mid;
        while(lo+1<hi){
            mid = (hi+lo)/2;
            check(mid);
            if(ok){
                lo=mid;
            }
            else hi=mid;
        }
        long long int sollow=check(lo);
        long long int solvehi=check(hi);
        if(sollow >= solvehi) cout<<sollow<<" "<<lo<<endl;
        else cout<<solvehi<<" "<<hi<<endl;
    }

    return 0;
}