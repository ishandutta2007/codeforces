#include <iostream>
#include <vector>
using namespace std;
int main ()
{int n,p,k,s=0,w;
vector <int> an[100009],o,e;
int l=0;
cin>>n>>k>>p;
for (int i=0; i<n; i++)
{int r; 
cin>>r;
if(r%2==1) {s++; o.push_back(r);}
else e.push_back(r);

}
w=e.size();
if (s<k-p || (s-k+p)%2==1 || p-(s-k+p)/2>w){cout<<"NO"<<endl;return 0;}
for (int i=0; i<k-p; i++)
an[i].push_back(o[i]);
l=k-p;
if (p==0) l--;
for (int i=k-p; i<o.size(); i+=2)
{an[l].push_back(o[i]);
an[l].push_back(o[i+1]);
if(l<k-1)l++;
}
for (int i=0; i<e.size(); i++)
{an[l].push_back(e[i]);
if (l<k-1) l++;
} 
cout<<"YES"<<endl;
for (int i=0; i<k; i++)
{cout<<an[i].size(); 
for (int j=0; j<an[i].size(); j++)
cout<<" "<<an[i][j];
cout<<endl;
}
return 0;
}