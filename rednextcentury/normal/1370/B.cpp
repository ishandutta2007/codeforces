#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> odd,even;
        for (int i=1;i<=2*n;i++){
            int x;
            cin>>x;
            if (x%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        if ((int)odd.size()%2)
            odd.pop_back(), even.pop_back();
        else {
            if (even.size()>1)even.pop_back(),even.pop_back();
            else odd.pop_back(),odd.pop_back();
        }
        while(even.size()) odd.push_back(even.back()), even.pop_back();
        while(odd.size()>1){
            cout<<odd.back();
            odd.pop_back();
            cout<<' '<<odd.back()<<endl;
            odd.pop_back();
        }
        
    }
}