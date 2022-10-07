#include<bits/stdc++.h>
using namespace std;
int d[2009];
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout<<"? "<<1<<endl;
    int a= 0,b=0;
    vector<int> A,B;
    for(int i= 1; i <= n; i++){
        cin >> d[i];
        if(d[i] % 2 == 0) A.push_back(i);
        else B.push_back(i);
    }
    if(A.size() > B.size()) swap(A,B);
    vector<pair<int,int> > ans;
    for(int x : A){
        if(x != 1){
            cout<<"? "<<x<<endl;
            for(int i= 1; i <= n; i++)
                cin >>d[i];
        }
         for(int i= 1; i <= n; i++){
            if(d[i] == 1) ans.push_back({x,i});
         }
    }
    cout<<"!"<<endl;
    for(auto x : ans)
        cout<<x.first<<" "<<x.second<<endl;

}