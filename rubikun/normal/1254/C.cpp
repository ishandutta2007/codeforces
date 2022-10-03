#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<50;
 
bool compare(pair<int,ll> a,pair<int,ll> b){
    return a.second<b.second;
}
 
int main(){
    
    int N;cin>>N;
    vector<pair<int,ll>> left,right;
    for(int i=3;i<=N;i++){
        int which;
        ll size;
        cout<<"2 1 2 "<<i<<endl;
        cin>>which;
        cout<<"1 1 2 "<<i<<endl;
        cin>>size;
        if(which==-1) right.push_back({i,size});
        else left.push_back({i,size});
    }
    
    sort(all(right),compare);
    sort(all(left),compare);
    
    vector<int> ans1={1},ans2,ans3={2},ans4;
    
    for(int i=0;i<int(right.size())-1;i++){
        int a=right[i].first;
        cout<<"2 "<<1<<" "<<a<<" "<<right[right.size()-1].first<<endl;
        int which;
        cin>>which;
        
        if(which==1) ans1.push_back(a);
        else ans2.push_back(a);
    }
    
    if(right.size()>=1) ans1.push_back(right[right.size()-1].first);
    
    for(int i=0;i<int(left.size())-1;i++){
        int a=left[i].first;
        cout<<"2 "<<2<<" "<<a<<" "<<left[left.size()-1].first<<endl;
        int which;
        cin>>which;
        
        if(which==1) ans3.push_back(a);
        else ans4.push_back(a);
    }
    
    if(left.size()>=1) ans3.push_back(left[left.size()-1].first);
    
    reverse(all(ans2));
    reverse(all(ans4));
    
    cout<<"0";
    for(int a:ans1) cout<<" "<<a;
    for(int a:ans2) cout<<" "<<a;
    for(int a:ans3) cout<<" "<<a;
    for(int a:ans4) cout<<" "<<a;
    cout<<endl;
}