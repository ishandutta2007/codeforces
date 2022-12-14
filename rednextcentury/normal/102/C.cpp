# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
struct p
{
    int a;
    int b;
};
p arr[100];
char c[26];
string s;
bool comp(p n1,p n2)
{
    return n1.b<n2.b;
}
int main()
{
    cin>>s;
    int dif=0;
    for (int i=0;i<s.length();i++)
    {
        arr[s[i]-97].a=int (s[i]);
        arr[s[i]-97].b++;
        if (arr[s[i]-97].b==1)
            dif++;
    }
    sort (arr,arr+26,comp);
    int m;
    cin>>m;
    int ans=dif;
    int loc=0;
    for (int i=0;i<26;i++)
    {
        if (arr[i].b<=m && arr[i].b!=0)
        {
            ans--;
            m=m-arr[i].b;
            c[loc]=char (arr[i].a);
            
            loc++;
        }
    }
    cout<<ans<<endl;
    for (int i=0;i<s.length();i++)
    {
        int x=0;
        for (x=0;x<loc;x++)
        {
            if (s[i]==c[x])
                break;
        
        }
        if (x==loc)
            cout<<s[i];
    
    
    
    }
    cout<<endl;

}