# include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d,e,f;
    cin>>d>>e>>f;
    int l=0;
    if (a==d) l++;
    if (b==e) l++;
    if (c==f) l++;
    if (l>=1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}