#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
typedef long long Int;

struct human
    {
    string friendname;
    Int rank;
    };

map<string,Int> mymap2;
map<string,Int>::iterator myit2;



/// I JUST SPAM


human humans[1001];

bool SortHumans(human a,human b)
    {
    if (a.rank>b.rank)return true;
    else if (a.rank<b.rank)return false;
    else
        {
        return (a.friendname<b.friendname);
        }
    }

Int Points(Int tp)
    {
    if (tp==1)return 15;
    else if (tp==2) return 10;
    else return 5;
    }

int main()
    {
    Int n,people=0;
    Int i,j;
    Int p1,p2;
    Int type;
    string name;
    string inp;

    for (i=0;i<=1000;i++)humans[i].rank=0;

    cin>>name;
    people++;
    mymap2.insert( pair<string,Int>( name,people ) );

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
        {
        cin>>name;
        ///cout<<name<<endl;

        myit2=mymap2.find( name );
        if (myit2==mymap2.end())
            {
            people++;
            mymap2.insert( pair<string,Int>(name,people) );
            humans[people].friendname=name;
            p1=people;
            }
        else p1=(*myit2).second;

        cin>>inp;

        if (inp[0]=='p') type=1;
        else if (inp[0]=='c') type=2;
        else type=3;

        if (type==1 || type==2)cin>>inp;

        cin>>inp;
        ///cout<<inp<<endl;

        name.clear();

        for (j=0;j<inp.length()-2;j++)
            {
            name=name+inp[j];
            }
        ///cout<<name<<" converted"<<endl;

        myit2=mymap2.find( name );
        if (myit2==mymap2.end())
            {
            ///cout<<"new name "<<name<<endl;
            people++;
            mymap2.insert( pair<string,Int>(name,people) );
            humans[people].friendname=name;
            p2=people;
            }
        else p2=(*myit2).second;

        if (p1==1)
            {
            humans[p2].rank+=Points(type);
            }
        else if (p2==1)
            {
            humans[p1].rank+=Points(type);
            }

        cin>>inp;
        }

    sort(humans+2,humans+1+people,SortHumans);

    for (i=2;i<=people;i++)
        {
        cout<<humans[i].friendname<<"\n";
        }
    return 0;
    }