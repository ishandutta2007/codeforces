#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

string m1;
string m2;
int l1,l2;

int gcd( int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

bool more (char a, char b)
{
    return ((a=='R'&&b=='S')||(a=='S'&&b=='P')||(a=='P'&&b=='R'));
}

int f1(int i)
{
    if (more(m1[i%l1],m2[i%l2])) return 1;
    return 0;
}
int f2(int i)
{
    if (more(m2[i%l2],m1[i%l1])) return 1;
    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin >> n;
    getchar();
    getline(cin,m1);
    getline(cin,m2);

    l1=(int)m1.size();
    l2=(int)m2.size();

    int nok=(l1*l2)/gcd(l1,l2);

    int m=n/nok;
    int count1=0, count2=0;
    for (int i=0;i<nok;i++)
    {
        count1+=f2(i);
        count2+=f1(i);
    }
    count1*=m;
    count2*=m;
    for (int i=0;i<n-m*nok;i++)
    {
        count1+=f2(i);
        count2+=f1(i);
    }
    cout << count1 << " "<<count2;
    return 0;
}