#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
pair<int,int> rotate_point(pair<int,int> C,pair<int,int> P)
{
    int s = 1;
    int c = 0;

    // translate point back to origin:
    P.x -= C.x;
    P.y -= C.y;

    int xnew = P.x * c - P.y * s;
    int ynew = P.x * s + P.y * c;

    // translate point back:
    P.x = xnew + C.x;
    P.y = ynew + C.y;
    return P;
}
int dist(pair<int,int> A,pair<int,int> B){
    return (A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second);
}
bool check(vector<pair<int,int> > vec){
    map<int,int> mp;
    for (int i=0;i<vec.size();i++) {
        for (int j=i+1;j<vec.size();j++){
            mp[dist(vec[i],vec[j])]++;
        }
    }
    int mn=1e9,mx=0;
    for (auto p:mp){
        mn=min(mn,p.second);
        mx=max(mx,p.second);
    }
    if (mp.size()==2 && mn==2 && mx==4 && mp[0]==0)return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        vector<pair<int,int> > vec(4);
        vector<pair<int,int> > c(4);
        int ok = 1e9;
        for (int i=0;i<4;i++)
            cin>>vec[i].x>>vec[i].y>>c[i].x>>c[i].y;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                for (int k=0;k<4;k++){
                    for (int l=0;l<4;l++){
                        if (check(vec))ok=min(ok,i+j+k+l);
                        vec[3]=rotate_point(c[3],vec[3]);
                    }
                    vec[2]=rotate_point(c[2],vec[2]);
                }
                vec[1]=rotate_point(c[1],vec[1]);
            }
            vec[0]=rotate_point(c[0],vec[0]);
        }
        if(ok>=1e9)cout<<-1<<endl;
        else cout<<ok<<endl;
    }
}