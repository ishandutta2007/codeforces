#include<bits/stdc++.h>
using namespace std;
int f[10009];
main(){
    int m, n;
    cin >> m >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        cout <<1 << endl;
        fflush(stdout) ;
        int x;
        cin>>x;
        if(x == 0){
            return 0;
        }
        if(x == -1) f[i] = -1;
        else f[i] = 1;
    }
    int qc = 0;
    int lo = 1, hi = m;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        cout << mid << endl;
        fflush(stdout) ;
        int k;
        cin>> k;
        if(!k) return 0;
        k *= f[qc];
        qc = (qc+ 1)%n;
        if(k == 1) lo = mid + 1;
        else hi = mid - 1;
    }
    
}