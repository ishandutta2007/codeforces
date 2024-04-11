#include<bits/stdc++.h>
using namespace std;
string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string p="What are you doing while sending ";//+(char)'"';//"
string t="? Are you busy? Will you send ";
string r="?";
long long l[1000000];
char f(long long n, long long k)
{
  //  cout<<l[n]<<endl;
  if(n<=55 && k>=l[n]) return '.';
if(n==0) return s[k];
  if(n>55) {
        if(k<p.size()*(n-55)) return p[k%p.size()];
  return f(55,k-p.size()*(n-55));}
  if(k<p.size()) return p[k];
  if(k<p.size()+l[n-1]) return f(n-1,k-p.size());
  if(k<p.size()+l[n-1]+t.size()) return t[k-p.size()-l[n-1]];
  if(k<p.size()+l[n-1]+t.size()+l[n-1]) return f(n-1,k-p.size()-l[n-1]-t.size());
  return r[k-p.size()-l[n-1]-t.size()-l[n-1]];
}
main()
{
    p+='"';
    t='"'+t+'"';
    r='"'+r;
   // cout<<p<<t<<r<<endl;
  //  long long p1=p.size();
    l[0]=s.size();
    for (long long i=1; i<=56; i++)
    {
        l[i]=2*l[i-1]+p.size()+t.size()+r.size();
        //cout<<l[i]<<endl;
    }
    long long q;
    cin>>q;
    for (long long i=0; i<q; i++)
    {
      long long n,k;
      cin>>n>>k;
      cout<<f(n,k-1);

    }
}