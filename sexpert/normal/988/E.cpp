#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int l = n.length() - 1;
    vector<int> zd, td, fd, sd;
    for(int i = l; i >= 0; i--)
    {
        int c = int(n[i]) - '0';
        if(c == 0) zd.push_back(l - i);
        if(c == 2) td.push_back(l - i);
        if(c == 5) fd.push_back(l - i);
        if(c == 7) sd.push_back(l - i);
    }
    int dist = 5000;
    if(zd.size() <= 1 && fd.size() == 0)
    {
        cout << -1;
        return 0;
    }
    if(zd.size() >= 2)
    {
        dist = min(dist, zd[0] + zd[1] - 1);
        //cout << dist << endl;
    }
    if(fd.size() >= 1)
    {
        int f = fd[0];
        if(td.size() > 0)
        {
            int t = td[0], k = 0, i = 1;
            if((f == l || t == l) && n[1] == '0')
                while(i <= l && n[i] == '0') {
                    k++;
                    i++;
                }
            if(t == 0) dist = min(dist, f + k);
            else if(f < t) dist = min(dist, f + t - 1 + k);
            else dist = min(dist, f + t + k);
            //cout << dist << endl;
        }
        if(sd.size() > 0)
        {
            int t = sd[0], k = 0, i = 1;
            if((f == l || t == l) && n[1] == '0')
                while(i <= l && n[i] == '0') {
                    k++;
                    i++;
                }
            if(t == 0) dist = min(dist, f + k);
            else if(f < t) dist = min(dist, f + t - 1 + k);
            else dist = min(dist, f + t + k);
            //cout << dist << endl;
        }
        if(zd.size() > 0)
        {
            int z = zd[0];
            if(f == 0) dist = min(dist, z);
            else if(z < f) dist = min(dist, z + f - 1);
            else dist = min(dist, z + f);
            //cout << dist << endl;
        }
    }
    cout << dist << endl;
}