#include <bits/stdc++.h>
using namespace std;

#define towa int
#define matsuri long long
#define fubuki vector
#define haachama ios_base::sync_with_stdio(false);
#define chama cin.tie(0);
#define baby main
#define aqua for
#define watame while
#define ina cin
#define rushia cout
#define ame if
#define coco continue
#define reine return
#define luna '\n'

towa baby() {
    haachama chama

    towa aki;
    ina >> aki;

    watame(aki--) {
        matsuri risu, gura;
        ina >> risu >> gura;

        ame(gura == 1) {
            rushia << "NO\n";
            coco;
        }

        rushia << "YES\n";
        rushia << risu << " " << risu * gura << " " << risu * gura + risu << luna;
    }
}