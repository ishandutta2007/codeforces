
#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
string str,a,b,c,d,e;
int main()
{
    a="Danil";
    b= "Olya";
    c= "Slava";
    d= "Ann";
    e="Nikita";
    cin>>str;
    size_t fi = str.find(a, 0);
    int num=0;
    while (fi!=str.npos)
    {
        num++;
        fi = str.find(a, fi + 1);
    }
    fi = str.find(b, 0);
    while (fi!=str.npos)
    {
        num++;
        fi = str.find(b, fi + 1);
    }
    fi = str.find(c, 0);
    while (fi!=str.npos)
    {
        num++;
        fi = str.find(c, fi + 1);
    }
    fi = str.find(d, 0);
    while (fi!=str.npos)
    {
        num++;
        fi = str.find(d, fi + 1);
    }
    fi = str.find(e, 0);
    while (fi!=str.npos)
    {
        num++;
        fi = str.find(e, fi + 1);
    }
    if(num==1) printf("YES\n"); else printf("NO\n");
    return 0;
}