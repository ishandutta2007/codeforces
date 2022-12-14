#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int cur=0;
        vector<int> vec;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='.')cur++;
            else
            {
                if (cur>=b)vec.push_back(cur);
                cur=0;
            }
        }
        if (cur>=b)vec.push_back(cur);
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        if (vec.size()==0) {
            cout<<"NO\n";
            continue;
        } else if (vec.size()>1 && vec[1]>=2*b) {
            cout<<"NO\n";
            continue;
        } else if (vec[0]<a){
            cout<<"NO\n";
            continue;
        }
        int N = vec[0];
        int A=0,B=0;
        for (int i=1;i<vec.size();i++)
            B+=(vec[i]>=b && vec[i]<a);
        if (B>0) {
            cout<<"NO\n"<<endl;
            continue;
        }
        int numLeft = vec.size()-1;
        bool can=0;
        for (int i=0;i<=N-a;i++)
        {
            int L = i, R = (N-a-i);
            if (L>=2*b || R>=2*b)continue;
            if (L>=b && L<a)continue;
            if (R>=b && R<a)continue;
            int left = numLeft+(L>=a)+(R>=a);
            if (left%2==0)can=1;
        }
        if (can)cout<<"YES\n";
        else cout<<"NO\n"<<endl;
    }
}