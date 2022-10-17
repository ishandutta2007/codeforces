#include <iostream>
#include <vector>
using namespace std;

string inp;
vector<long long> runs;

long long ct[2][2];
long long jh[100005][2];

int main(){
    jh[1][0] = 0;
    jh[1][1] = 1;

    for(int h = 2; h <= 100000; h++){
        jh[h][0] = jh[h-1][0] + h/2;
        jh[h][1] = jh[h-1][1] + (h+1)/2;
    }

    ios_base::sync_with_stdio(false);
    cin >> inp;

    for(int i=0; i<inp.length();){
        int run = 0, ii = i;
        while(i<inp.length() && inp[i] == inp[ii]){
            i++;
            run++;
        }
        runs.push_back(run);
    }

    long long odd = 0, even = 0;

    for(int i=0; i<runs.size(); i++){
        odd += jh[runs[i]][1];
        even += jh[runs[i]][0];

        long long here_odd = (runs[i]+1)/2;
        long long here_even = runs[i]/2;

        odd += here_odd * ct[i%2][0] + here_even * ct[i%2][1];
        even += here_odd * ct[i%2][1] + here_even * ct[i%2][0];

        if(runs[i]%2){
            swap(ct[0][0], ct[0][1]);
            swap(ct[1][0], ct[1][1]);
        }

        ct[i%2][0] += here_even;
        ct[i%2][1] += here_odd;
    }

    cout << even << " " << odd << endl;
    return 0;
}