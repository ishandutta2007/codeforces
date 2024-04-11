#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int N = 10000000;
    int lp[N+1];
    int c[N+1];
    vector<int> pr;
    bool kv[N+1];
    for (int i=0;i<=N;i++) kv[i]=false;
    for (int i=1;i*i<=N;i++)
    {
        kv[i*i]=true;
    }
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            c[i]=1;
            pr.push_back (i);
        }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
    {
        lp[i * pr[j]] = pr[j];
        c[i*pr[j]]=i;
    }
    }

    int n,a;
    long long int result=0;
    cin >> a >> n;

    for (int i=a;i<n+a;i++)
    {
        int j=i;
        long long int t=1;
        while (!kv[j]) 
        {
            if (lp[j]!=lp[c[j]]) t*=lp[j]; else j=c[j];
            j=c[j];
        }
        //cout << i << " " << t << endl;
        result+=t;
    }
    cout << result;


    return 0;
}