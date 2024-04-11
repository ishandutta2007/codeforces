#include<bits/stdc++.h>
using namespace std;
int f[200009];
main(){
    double n, s;
    cin >> n >> s;
    if(n == 2){
        cout<<s<<endl;
        return 0;
    }
    for(int i = 1; i<= (int)n-1; i++){
        int a,b ;
        cin >> a >> b;
        f[a]++;
        f[b]++;
    }
    double k = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] == 1) k++;
    }
    cout << printf("%.9f", 2*(double)s/k) << endl;

}