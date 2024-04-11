#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int N;
    cin>>N;
    int ind = 0;
    int best = 0;
    vector<int> Cnt(1e6+179);
    for(int i = 0; i < N; ++ i)
    {
        int a;
        cin>>a;
        Cnt[a]++;
        if (Cnt[a] > best)
        {
            best = Cnt[a];
            ind = a;
        }
    }
    cout<<ind<<endl;
}