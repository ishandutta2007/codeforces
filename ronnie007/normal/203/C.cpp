#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


unsigned long long n,d;
unsigned long long cena1,cena2;


struct tuhla
    {
    unsigned long long a,b;
    unsigned long long number;
    };

bool f(struct tuhla x,struct tuhla y);
vector<struct tuhla> v;
vector <int> ans;
int main()
    {
    unsigned long long i;
    v.clear();
    ans.clear();
    int br=0;
    scanf("%d%d",&n,&d);
    scanf("%d%d",&cena1, &cena2);
    struct tuhla p;
    for(i=0;i<n;i++)
        {
        cin>>p.a>>p.b;
        p.number=i+1;
        v.push_back(p);
        }
    sort(v.begin(),v.end(),f);
    //cout<<v[0].a;
    for(i=0;i<n;i++)
        {
        if(d>=(cena1*v[i].a+cena2*v[i].b))
            {
            br++;
            ans.push_back(v[i].number);
            d-=(cena1*v[i].a+cena2*v[i].b);
            }
        }
    cout<<br<<"\n";
    for(i=0;i<ans.size();i++)
        {
        cout<<ans[i]<<" ";
        }
    cout<<"\n";
    return 0;
    }



bool f(struct tuhla x,struct tuhla y)
    {
    if(cena1*x.a+cena2*x.b<cena1*y.a+cena2*y.b)return true;
    return false;
    }