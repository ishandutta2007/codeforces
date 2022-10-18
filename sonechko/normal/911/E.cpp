#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define ld long double
#define mp make_pair

const int N = 2e5 + 11;

int a[N];

int main()
{
         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
         int n,k;
         cin>>n>>k;
         vector<int> v;
         int d=1;
         for (int i=1; i<=k; i++)
         {
                   int l;
                   cin>>l;
                   a[i]=l;
                   v.pb(l);
                   while (v.size()>0&&v.back()==d)
                   {
                             v.pop_back();
                             d++;
                   }
         }
         for (int p=1; p<v.size(); p++)
         if (v[p]>v[p-1]) {cout<<-1<<endl; return 0;}
         for (int i=1; i<=k; i++)
         cout<<a[i]<<" ";
         while (v.size()>0)
         {
                   int c=v.back();
                   while (c>d)
                   {
                             cout<<c-1<<" ";
                             c--;
                   }
                   d=v.back()+1;
                   v.pop_back();
         }
         for (int p=n; p>=d; p--)
         cout<<p<<" ";
         cout<<endl;
}