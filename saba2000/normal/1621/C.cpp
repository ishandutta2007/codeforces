#include<bits/stdc++.h>
using namespace std;
int f[200009];
int p[200009];
int ask(int x){
    cout <<"? "<<x<<endl;
    int y;
    cin>>y;
    return y;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            f[i] = 0;
        for(int i = 1; i <= n; i++){
            if(f[i] == 1) continue;
            while(ask(i) != i) {}
            int x = i;
            while(1){
                int y = ask(i);
                f[y] = 1;
                p[x] = y;
                if(y == i) break;
                x = y;
            }
        }
        cout<<"! ";
        for(int i = 1; i <= n; i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }


}