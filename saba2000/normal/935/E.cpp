#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,pair<int,int> > M[200009];
int ans=0;
pair<int,int> f(string s, int p, int m, int L, int R)
{

    pair<int,int> K={L,R};
    if(p<0 || m<0) return {-100000,100000};
    if(M[p].find({L,R})!=M[p].end())
        return M[p][K];
    if(s.size()==1) return {s[0]-'0',s[0]-'0'};
    ans++;
 string a="",b="";
  int  o1=0;
  int cnt=0;
   int  fl=0;
    int mid;
    for(int i=1 ;i<s.size()-1; i++)
    {
        if(s[i]=='(') cnt++;
        else if(s[i]==')') cnt--;
        if(fl==0) a+=s[i];else b+=s[i];
        if(s[i]=='?')
        {
            if(fl==0) o1++;

        }
        if(cnt==0 && fl==0) {fl=1;mid=i+L; i++;}
    }
    int ans1=-100000,ans2=100000;
    for (int i = max(0,o1-m); i<= min(o1,p); i++)
    {
        int p1 = i, m1= o1-p1;
        pair<int,int> A = f(a,p1,m1,L+1,mid);
        pair<int,int> B1= f(b,p-p1-1,m-m1,mid+2,R-1);
        pair<int,int> B2= f(b,p-p1,m-m1-1,mid+2,R-1);
        ans1=max(ans1,A.first+B1.first);
        ans1=max(ans1,A.first-B2.second);
        ans2=min(ans2,A.second+B1.second);
        ans2=min(ans2,A.second-B2.first);
    }
    M[p][K]={ans1,ans2};
    return {ans1,ans2};
}
main()
{
    string s;
    cin >> s;
    int p,m;
    cin >> p >>m;
    cout<< f(s,p,m,0,s.size()-1).first<<endl;
}