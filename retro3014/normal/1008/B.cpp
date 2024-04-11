#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct S{
    int x, y;
};

int N;
vector<S> v;
int h;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        S tmp;
        scanf("%d%d", &tmp.x, &tmp.y);
        if(tmp.x>tmp.y)
        {
            int t=tmp.x;
            tmp.x=tmp.y;
            tmp.y=t;
        }
        if(i==1)
        {
            h=tmp.y;
        }
        else
        {
            if(h>=tmp.y)
            {
                h=tmp.y;
            }
            else if(h>=tmp.x)
            {
                h=tmp.x;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
        
    }
    cout<<"YES";
    return 0;
}