#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

struct gr
    {
    bool asfl;
    Int ver;
    };
struct tl
    {
    bool masfl;
    Int ver;
    };
Int n,m;
vector<gr> graph[101];
bool TFO[101];
Int actions[101];
Int acL=0;

Int DoIt(Int p,bool doornot)
    {
    tl tail[101];
    Int tL=0;
    Int uk;
    Int didtfo[101];
    Int dtL=0;
    Int mustbe[101];
    Int i;
    Int incremented=0;
    bool called[101];

    for (i=0;i<=100;i++)
        {
        mustbe[i]=-1;
        called[i]=false;
        }
    tL=1;
    tail[tL].ver=p;
    tail[tL].masfl=doornot;
    called[p]=true;

    if (doornot)
    mustbe[p]=1;
    else
    mustbe[p]=0;

    uk=1;

    while(uk<=tL)
        {
        TFO[ tail[uk].ver ]=true;
        dtL++;
        didtfo[dtL]=tail[uk].ver;

        if (tail[uk].masfl)
            {
            acL++;
            incremented++;
            actions[acL]=tail[uk].ver;
            }

        for (i=0;i<graph[ tail[uk].ver ].size();i++)
            {
            if ( graph[tail[uk].ver][i].asfl )
                {
                if (mustbe[ tail[uk].ver ]==1)
                    {
                    if (TFO[ graph[tail[uk].ver][i].ver ])
                        {
                        if ( mustbe[ graph[tail[uk].ver][i].ver ]!=1 )
                            {
                            for (i=1;i<=dtL;i++)
                                {
                                TFO[ didtfo[i] ]=false;
                                }
                            acL=acL-incremented;
                            return -1;
                            ///Impossible
                            }
                        }
                    else
                        {
                        if (!called[ graph[tail[uk].ver][i].ver ])
                            {
                            tL++;
                            tail[tL].ver=graph[tail[uk].ver][i].ver;
                            tail[tL].masfl=true;
                            mustbe[ graph[tail[uk].ver][i].ver ]=1;
                            called[ graph[tail[uk].ver][i].ver ]=true;
                            }
                        else
                            {
                            if ( mustbe[ graph[tail[uk].ver][i].ver ]!=1 )
                                {
                                for (i=1;i<=dtL;i++)
                                    {
                                    TFO[ didtfo[i] ]=false;
                                    }
                                acL=acL-incremented;
                                return -1;
                                ///Impossible
                                }
                            }
                        }
                    }
                else
                    {
                    if (TFO[ graph[tail[uk].ver][i].ver ])
                        {
                        if ( mustbe[ graph[tail[uk].ver][i].ver ]!=0 )
                            {
                            for (i=1;i<=dtL;i++)
                                {
                                TFO[ didtfo[i] ]=false;
                                }
                            acL=acL-incremented;
                            return -1;
                            ///Impossible
                            }
                        }
                    else
                        {
                        if (!called[ graph[tail[uk].ver][i].ver ])
                            {
                            tL++;
                            tail[tL].ver=graph[tail[uk].ver][i].ver;
                            tail[tL].masfl=false;
                            mustbe[ graph[tail[uk].ver][i].ver ]=0;
                            called[ graph[tail[uk].ver][i].ver ]=true;
                            }
                        else
                            {
                            if ( mustbe[ graph[tail[uk].ver][i].ver ]!=0 )
                                {
                                for (i=1;i<=dtL;i++)
                                    {
                                    TFO[ didtfo[i] ]=false;
                                    }
                                acL=acL-incremented;
                                return -1;
                                ///Impossible
                                }
                            }
                        }
                    }
                }
            else
                {
                if (mustbe[ tail[uk].ver ]==1)
                    {
                    if (TFO[ graph[tail[uk].ver][i].ver ])
                        {
                        if ( mustbe[ graph[tail[uk].ver][i].ver ]!=0 )
                            {
                            for (i=1;i<=dtL;i++)
                                {
                                TFO[ didtfo[i] ]=false;
                                }
                            acL=acL-incremented;
                            return -1;
                            ///Impossible
                            }
                        }
                    else
                        {
                        if (!called[ graph[tail[uk].ver][i].ver ])
                            {
                            tL++;
                            tail[tL].ver=graph[tail[uk].ver][i].ver;
                            tail[tL].masfl=false;
                            mustbe[ graph[tail[uk].ver][i].ver ]=0;
                            called[ graph[tail[uk].ver][i].ver ]=true;
                            }
                        else
                            {
                            if ( mustbe[ graph[tail[uk].ver][i].ver ]!=0 )
                                {
                                for (i=1;i<=dtL;i++)
                                    {
                                    TFO[ didtfo[i] ]=false;
                                    }
                                acL=acL-incremented;
                                return -1;
                                ///Impossible
                                }
                            }
                        }
                    }
                else
                    {
                    if (TFO[ graph[tail[uk].ver][i].ver ])
                        {
                        if ( mustbe[ graph[tail[uk].ver][i].ver ]!=1 )
                            {
                            for (i=1;i<=dtL;i++)
                                {
                                TFO[ didtfo[i] ]=false;
                                }
                            acL=acL-incremented;
                            return -1;
                            ///Impossible
                            }
                        }
                    else
                        {
                        if (!called[ graph[tail[uk].ver][i].ver ])
                            {
                            tL++;
                            tail[tL].ver=graph[tail[uk].ver][i].ver;
                            tail[tL].masfl=true;
                            mustbe[ graph[tail[uk].ver][i].ver ]=1;
                            called[ graph[tail[uk].ver][i].ver ]=true;
                            }
                        else
                            {
                            if ( mustbe[ graph[tail[uk].ver][i].ver ]!=1 )
                                {
                                for (i=1;i<=dtL;i++)
                                    {
                                    TFO[ didtfo[i] ]=false;
                                    }
                                acL=acL-incremented;
                                return -1;
                                ///Impossible
                                }
                            }
                        }
                    }
                }
            }

        uk++;
        }
    return incremented;
    }

int main()
    {
    Int i;
    Int a,b,c;
    gr k;
    Int retr;
    Int ctr=0;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=m;i++)
        {
        scanf("%I64d %I64d %I64d",&a,&b,&c);
        if (c==0)
        k.asfl=false;
        else
        k.asfl=true;

        k.ver=b;

        graph[a].push_back(k);
        k.ver=a;
        graph[b].push_back(k);
        }
    for (i=0;i<=100;i++)
    TFO[i]=false;

    for (i=1;i<=n;i++)
        {
        if (!TFO[i])
            {
            retr=DoIt(i,true);
            if (retr==-1)
                {
                retr=DoIt(i,false);
                if (retr==-1)
                    {
                    cout<<"Impossible"<<endl;
                    return 0;
                    }
                }
            }
        }
    cout<<acL<<endl;
    for (i=1;i<=acL;i++)
        {
        cout<<actions[i];
        if (i==acL)
        cout<<endl;
        else
        cout<<" ";
        }
    return 0;
    }