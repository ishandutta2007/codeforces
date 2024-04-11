#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[4];
vector<int> vec;
bool Try(int x){
    int b[4];
    for (int i=0;i<4;i++)b[i]=a[i];
    if (b[x]==0)return 0;
    vec.clear();
    int cur = x;
    while(1){
        if (b[0]+b[1]+b[2]+b[3]==0)break;
        b[cur]--;
        vec.push_back(cur);
        if (b[cur]<0)return 0;
        if (cur==3)cur--;
        else if (cur==0)cur++;
        else {
            if (b[cur-1]==0)cur++;
            else if (b[cur+1]==0)cur--;
            else {
                if(cur==1)cur--;
else cur++;
            }
        }
    }
    for (int i=1;i<vec.size();i++){
        if (abs(vec[i]-vec[i-1])!=1)return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i=0;i<4;i++)cin>>a[i];
    for (int i=0;i<4;i++){
        if (Try(i)){
            cout<<"YES"<<endl;
            for (auto x:vec)cout<<x<<' ';
            cout<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}