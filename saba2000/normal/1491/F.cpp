
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int x = 0;
    vector<int> ans;
    for(int i = 2; i <= n; i++){
        cout << "? "<<i-1<<" "<<1<<endl;
        for(int j = 1; j < i; j++)
            cout<<j<<" ";
        cout<<endl<<i<<endl;
        int k;
        cin>>k;
        if(k) {
            x = i;
            int l = 1, r = i-1;
            while(l < r){
                int mid = (l + r)/2;
                cout << "? "<<mid <<" "<<1<<endl;
                for(int j = 1; j <= mid; j++)
                    cout<<j<<" ";
                cout<<endl<<i<<endl;
                int k;
                cin>>k;
                if(k) r = mid;
                else l = mid + 1;
            }
            for(int j = 1; j < i; j++)
                if(j != l) ans.push_back(j);
            break;
        }
    }
    for(int i = x+1; i <= n; i++){
        cout <<"? 1 1"<<endl<<x<<endl<<i<<endl;
        int k;
        cin>>k;
        if(!k) ans.push_back(i);

    }
    cout<<"! "<<ans.size()<<" ";
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
}