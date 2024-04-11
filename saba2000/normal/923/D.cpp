#include<bits/stdc++.h>
using namespace std;
int sx[1000009], sy[1000009], sa[1000009], tx[100009], ty[100009], ta[100009];
bool Q(int a, int b, int c, int d){
        int sX = sx[b] - sx[a-1];
        int sR = min(b-a+1,sa[b]);
        int tX = tx[d] - tx[c-1];
        int tR = min(d-c+1,ta[d]);
        if(sX == 0 && tX != 0) {
            if(sR <= tR) return 0;
            sR = tR;
            sX = 2;
        }
        if(tR > sR) return 0;
        if((sX % 2) != (tX % 2)) return 0;
        if(sX > tX) return 0;
        if(sX != tX) return 1;
        if((sR % 3) != (tR % 3)) return 0;
        return 1;
}
//
main()
{
    string s;
    string t;
    cin >> s >> t;
    s= '?' + s; t= '?' + t;
    for (int i = 1; i< s.size(); i++){
            sx[i] = sx[i-1];
            sy[i] = sy[i-1];
            sa[i] = sa[i-1];
        if(s[i] =='B' || s[i] =='C') {sx[i] ++; sa[i] =0;}
        else {sy[i] ++; sa[i] ++;}
    }
    for (int i = 1; i< t.size(); i++){
            tx[i] = tx[i-1];
            ty[i] = ty[i-1];
            ta[i] = ta[i-1];
        if(t[i] =='B' || t[i] =='C') {tx[i] ++; ta[i] = 0;}
        else {ty[i] ++; ta[i] ++;}
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a,b,c,d;
        cin >>a >> b >> c >> d;
        cout << Q(a,b,c,d);
    }
}