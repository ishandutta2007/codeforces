
 #include<bits/stdc++.h>
using namespace std;
bool vis[1000000];
int main()
{
    int h1,h2;
    cin>>h1>>h2;
    int a,b;
    cin>>a>>b;
    h1=h1+8*a;
    a*=12,b*=12;
    int d=0;
    if (h1>=h2)
        cout<<0<<endl;
    else
    {
        d++;
        h1-=b;

        if (a<=b)
        {
            if (h1+a>=h2)
                cout<<0<<endl;
            else
                cout<<-1<<endl;
        }
        else
        {
            d=1;
            while(h1<h2)
            {
                h1+=a;
                if (h1>=h2)
                    break;
                h1-=b;
                d++;
            }
            cout<<d<<endl;
        }
    }
}