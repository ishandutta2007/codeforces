#include<iostream>

using namespace std;

int main ()
{
    int n,res=0,i;
    string s;

    ios::sync_with_stdio(false);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>s;

        if(s=="Tetrahedron")res+=4;
        if(s=="Cube")res+=6;
        if(s=="Octahedron")res+=8;
        if(s=="Dodecahedron")res+=12;
        if(s=="Icosahedron")res+=20;
    }

    cout<<res<<endl;

    return 0;
}