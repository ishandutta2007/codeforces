#include <iostream>
#include <map>
#include <fstream>
#define MAXN 510
using namespace std;
typedef pair<int, int> pii;
int T, N;
int a[MAXN], b[MAXN];
bool flag;
map<pii, int> m;
pii f(int s, int t)
{
    if(s > t)
    {
        swap(s, t);
    }
    return make_pair(s, t);
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        flag = true;
        cin>>N;
        m.clear();
        for(int j=0; j<N; j++)
        {
            cin>>a[j];
        }
        for(int j=0; j<N; j++)
        {
            cin>>b[j];
        }
        for(int j=0; j<N; j++)
        {
            ++m[f(a[j], a[N-1-j])];
            --m[f(b[j], b[N-1-j])];
        }
        for(map<pii, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            if(it -> second != 0)
            {
                flag = false;
                cout<<"No"<<endl;
                break;
            }
        }
        if(flag) cout<<"Yes"<<endl;
    }
}