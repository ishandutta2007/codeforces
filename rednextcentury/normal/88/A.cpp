
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
string v[]={"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
int dist(int a,int b)
{
    int ret=b-a;
    if (ret<0)
        ret+=12;
    return ret;
}
int main()
{
    int n=12;
    string x,y,z;
    cin>>x>>y>>z;
    int a=0,b=0,c=0;
    for (int i=0;i<12;i++)
    {
        if (v[i]==x)
            a=i;
        if (v[i]==y)
            b=i;
        if (v[i]==z)
            c=i;
    }
    if ( ((dist(a,b)==4 && dist(b,c)==3)) || ((dist(b,c)==4 && dist(c,a)==3)) || ((dist(a,c)==4 && dist(c,b)==3)) || ((dist(b,a)==4 && dist(a,c)==3)) || ((dist(c,b)==4 && dist(b,a)==3)) || ((dist(c,a)==4 && dist(a,b)==3)))
        cout<<"major"<<endl;
    else if ( ((dist(a,b)==3 && dist(b,c)==4)) || ((dist(b,c)==3 && dist(c,a)==4)) || ((dist(a,c)==3 && dist(c,b)==4)) || ((dist(b,a)==3 && dist(a,c)==4)) || ((dist(c,b)==3 && dist(b,a)==4)) || ((dist(c,a)==3 && dist(a,b)==4)))
        cout<<"minor"<<endl;
    else
        cout<<"strange"<<endl;
}