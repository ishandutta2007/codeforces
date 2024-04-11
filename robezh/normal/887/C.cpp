#include<cstdio>
#include<iostream>
using namespace std;

int p[50];

struct face {
    int a,b,c,d;
    face() {}
    face(int _a, int _b, int _c, int _d) {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
};

bool all_equal(int a, int b, int c, int d) {
    return a == b && b == c && c == d;
}

bool all_the_same(int a, int b, int c, int d) {
    return all_equal(p[a],p[b],p[c],p[d]);
}

bool rotate(face f1, face f2, face f3, face f4) {
    bool lans = all_the_same(f1.a, f1.b, f2.c, f2.d) && all_the_same(f2.a, f2.b, f3.c, f3.d)
                && all_the_same(f3.a, f3.b, f4.c, f4.d) && all_the_same(f4.a, f4.b, f1.c, f1.d);
    bool rans = all_the_same(f1.c, f1.d, f2.a, f2.b) && all_the_same(f2.c, f2.d, f3.a, f3.b)
                && all_the_same(f3.c, f3.d, f4.a, f4.b) && all_the_same(f4.c, f4.d, f1.a, f1.b);
    
    return lans || rans;
}

bool good(){
	bool ans1 = all_the_same(13,14,15,16) && all_the_same(17,18,19,20)
	    && rotate(face(1,3,2,4), face(5,7,6,8), face(9,11,10,12), face(22,24,21,23));
	bool ans2 = all_the_same(1,2,3,4) && all_the_same(9,10,11,12)
	    && rotate(face(13,14,15,16), face(5,6,7,8), face(17,18,19,20), face(21,22,23,24));
	bool ans3 = all_the_same(5,6,7,8) && all_the_same(21,22,23,24)
	    && rotate(face(17,19,18,20), face(3,4,1,2), face(14,16,13,15), face(9,10,11,12));
	return ans1 || ans2 || ans3;
}

int main() {
    for(int i = 1; i <= 24; i ++) {
        scanf("%d", &p[i]);
    }
    if(good()) printf("YES");
    else printf("NO");
    

}