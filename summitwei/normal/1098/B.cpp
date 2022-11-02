#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n, m;
vi nums[MN];
pii hsums[5][MN]; //alternating
pii vsums[5][MN];

int cases[15]; //count amt same

int getchar(char c){
    if(c == 'A') return 0;
    if(c == 'G') return 1;
    if(c == 'C') return 2;
    return 3;
}
char getval(int x){
    if(x == 0) return 'A';
    if(x == 1) return 'G';
    if(x == 2) return 'C';
    return 'T';
}

pii getpair(int x){
    if(x <= 2) return mp(0, x+1);
    if(x >= 5) return mp(2, 3);
    return mp(1, x-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    F0R(i, n){
        //nums[i].resize(m);
        F0R(j, m){
            char c;
            cin >> c;
            //nums[i][j] = getchar(c);
            nums[i].pb(getchar(c));
        }
    }

    F0R(i, n){
        F0R(j, m){
            int x = nums[i][j];
            //hsums[x][i]++;
            //vsums[x][j]++;
            if(i%2==0){
                hsums[x][j].f++;
            } else{
                hsums[x][j].s++;
            }
            if(j%2==0){
                vsums[x][i].f++;
            } else{
                vsums[x][i].s++;
            }
        }
    }

    /*F0R(i, n){
        F0R(j, 4){
            cout << vsums[j][i].f << " " << vsums[j][i].s << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    F0R(i, m){
        F0R(j, 4){
            cout << hsums[j][i].f << " " << hsums[j][i].s << " ";
        }
        cout << "\n";
    }*/

    //0-5 = use horiz, 6-11 = use vert

    F0R(cs, 6){
        pii asdf = getpair(cs);
        int a = asdf.f;
        int b = asdf.s;
        int c, d;
        if(a != 0 && b != 0) c = 0;
        else if(a != 1 && b != 1) c = 1;
        else c = 2;

        d = 6-a-b-c;
        
        //cout << cs << " " << a << " " << b << " " << c << " " << d << "\n";

        int sm = 0;
        F0R(i, m){
            if(i % 2 == 0){
                int c1 = hsums[a][i].f+hsums[b][i].s;
                int c2 = hsums[a][i].s+hsums[b][i].f;

                sm += max(c1, c2);
            } else{
                int c1 = hsums[c][i].f+hsums[d][i].s;
                int c2 = hsums[c][i].s+hsums[d][i].f;

                sm += max(c1, c2);
            }
        }
        cases[cs] = sm;

        sm = 0;
        F0R(i, n){
            if(i % 2 == 0){
                int c1 = vsums[a][i].f+vsums[b][i].s;
                int c2 = vsums[a][i].s+vsums[b][i].f;

                sm += max(c1, c2);
            } else{
                int c1 = vsums[c][i].f+vsums[d][i].s;
                int c2 = vsums[c][i].s+vsums[d][i].f;

                sm += max(c1, c2);
            }
        }
        cases[cs+6] = sm;
    }

    int mx = 0;
    int mxi = 0;

    F0R(i, 12){
        //cout << cases[i] << " ";
        if(cases[i] > mx){
            mx = cases[i];
            mxi = i;
        }
    }

    if(mxi < 6){
        pii asdf = getpair(mxi);
        int a = asdf.f;
        int b = asdf.s;
        int c, d;
        if(a != 0 && b != 0) c = 0;
        else if(a != 1 && b != 1) c = 1;
        else c = 2;

        d = 6-a-b-c;

        F0R(i, m){
            if(i % 2 == 0){
                int c1 = hsums[a][i].f+hsums[b][i].s;
                int c2 = hsums[a][i].s+hsums[b][i].f;

                //sm += max(c1, c2);
                if(c1 > c2){
                    F0R(j, n){
                        if(j%2 == 0){
                            nums[j][i] = a;
                        } else{
                            nums[j][i] = b;
                        }
                    }
                } else{
                    F0R(j, n){
                        if(j%2 == 0){
                            nums[j][i] = b;
                        } else{
                            nums[j][i] = a;
                        }
                    }
                }
            } else{
                int c1 = hsums[c][i].f+hsums[d][i].s;
                int c2 = hsums[c][i].s+hsums[d][i].f;

                //sm += max(c1, c2);
                if(c1 > c2){
                    F0R(j, n){
                        if(j%2 == 0){
                            nums[j][i] = c;
                        } else{
                            nums[j][i] = d;
                        }
                    }
                } else{
                    F0R(j, n){
                        if(j%2 == 0){
                            nums[j][i] = d;
                        } else{
                            nums[j][i] = c;
                        }
                    }
                }
            }
        }
    } else{
        mxi -= 6;

        pii asdf = getpair(mxi);
        int a = asdf.f;
        int b = asdf.s;
        int c, d;
        if(a != 0 && b != 0) c = 0;
        else if(a != 1 && b != 1) c = 1;
        else c = 2;

        d = 6-a-b-c;

        F0R(i, n){
            if(i % 2 == 0){
                int c1 = vsums[a][i].f+vsums[b][i].s;
                int c2 = vsums[a][i].s+vsums[b][i].f;

                //sm += max(c1, c2);
                if(c1 > c2){
                    F0R(j, m){
                        if(j%2 == 0){
                            nums[i][j] = a;
                        } else{
                            nums[i][j] = b;
                        }
                    }
                } else{
                    F0R(j, m){
                        if(j%2 == 0){
                            nums[i][j] = b;
                        } else{
                            nums[i][j] = a;
                        }
                    }
                }
            } else{
                int c1 = vsums[c][i].f+vsums[d][i].s;
                int c2 = vsums[c][i].s+vsums[d][i].f;

                //sm += max(c1, c2);
                if(c1 > c2){
                    F0R(j, m){
                        if(j%2 == 0){
                            nums[i][j] = c;
                        } else{
                            nums[i][j] = d;
                        }
                    }
                } else{
                    F0R(j, m){
                        if(j%2 == 0){
                            nums[i][j] = d;
                        } else{
                            nums[i][j] = c;
                        }
                    }
                }
            }
        }
    }

    //cout << "\n";
    F0R(i, n){
        F0R(j, m){
            cout << getval(nums[i][j]);
        }
        cout << "\n";
    }

    return 0;
}