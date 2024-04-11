#include <iostream>
using namespace std;

int N;
int L[5], R[5];


double wid(int i){ return R[i] - L[i] + 1; }

double ceq(int i, int t){
    if(t < L[i] || t > R[i]) return 0;
    return 1 / wid(i);
}

double cgt(int i, int t){
    return min(1.0, max(0.0, (R[i] - t) / wid(i)));
}

double cge(int i, int t){ return cgt(i, t) + ceq(i, t); }
double clt(int i, int t){ return 1 - cge(i, t); }
double cle(int i, int t){ return 1 - cgt(i, t); }

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> L[i] >> R[i];

    double res = 0;
    for(int sec = 1; sec <= 10000; sec++){
        double prob = 0;
        
        // case 1: unique maximum

        for(int i=0; i<N; i++){
            for(int m=1; m<(1<<(N-1)); m++){
                double cand = cgt(i, sec);
                for(int k=0, j=!i; k<N-1; k++){
                    if((m>>k)&1)
                        cand *= ceq(j, sec);
                    else
                        cand *= clt(j, sec);

                    j++;
                    if(i==j) j++;
                }
                prob += cand;                
            }
        }

        // case 2: non-unique maximum 

        for(int m=0; m<(1<<N); m++){
            double cand = 1;
            if(__builtin_popcount(m) < 2) continue;
            for(int k=0; k<N; k++){
                if((m>>k)&1)
                    cand *= ceq(k, sec);
                else
                    cand *= clt(k, sec);
            }
            prob += cand;
        }

        res += prob * sec;
    }

    cout.precision(20);
    cout << res << endl;
}