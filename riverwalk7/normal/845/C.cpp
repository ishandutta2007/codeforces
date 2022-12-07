#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define MAXN 202000
using namespace std;
struct video
{
    int l, r;
    video()
    {
        l = r = 0;
    }
    bool operator <(const video &rhs) const
    {
        return l < rhs.l;
    }
};
video x[MAXN];
vector<int> slot;
int N;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x[i].l>>x[i].r;
    }
    sort(x, x+N);
    for(int i=0; i<N; i++)
    {
        slot.push_back(x[i].r);
        if(slot.size()>=3)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(slot.size()==2)
        {
            if(slot[0]<slot[1])
            {
                swap(slot[0], slot[1]);
            }
            if(slot[1] < x[i+1].l)
            {
                slot.erase(slot.end()-1);
            }
        }
        if(slot.size()==1&&slot[0] < x[i+1].l)
        {
            slot.erase(slot.begin());
        }
    }
    cout<<"YES"<<endl;
}