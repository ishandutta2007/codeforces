#include <iostream>

using namespace std;
char s[2000001];
int main()
{
   string a,b;
   scanf("%s",&s);
   a=s;
   scanf("%s",&s);
   b=s;
   int n=a.length();
   int m=b.length();
   int i=0,j=0;
   while(a[i]=='0' && i<n)
    i++;
   while(b[j]=='0' && j<m)
    j++;
   if (n-i>m-j)
    cout<<">"<<endl;
   else if (n-i<m-j)
    cout<<"<"<<endl;
    else
    {
    while(j<m)
    {
        if (a[i]>b[j])
            cout<<">"<<endl;
        else if (a[i]<b[j])
            cout<<"<"<<endl;
        if (a[i]!=b[j])
            return 0;
        i++,j++;
    }
    cout<<"=\n";
    }
}