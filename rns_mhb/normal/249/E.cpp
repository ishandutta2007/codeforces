#include <stdio.h>

typedef long long LL;

const LL mo = 1000000000000000000LL;
const LL tt = 10000000000LL;
const LL B = 1000000000LL;

struct pnt{
	LL x, y;
	pnt(LL x = 0, LL y = 0):x(x), y(y){}
	pnt operator +(pnt a){
		LL ty = a.y + y;
		LL tx = a.x + x;
		if(ty>=mo) ty -= mo, tx++;
		return pnt(tx, ty);
	}
	pnt operator -(pnt a){
		LL ty = y - a.y;
		LL tx = x - a.x;
		if(ty<0)ty+=mo, tx--;
		return pnt(tx, ty);
	}
};

pnt C(LL a, LL b){
	LL tx = a / B, ty = a % B;
	LL sx = b / B, sy = b % B;
	LL t = sx * tx + (sx * ty + sy * tx) / B;
	LL k = ((sx * ty + sy * tx) % B) * B + ty * sy;
	t += k / mo;
	return pnt(t, k%mo);
}

pnt H(int a, int b){
	int x = b, y = b - 1, z = 2 * b - 1;
	if(x % 3 == 0) x /= 3;
	if(y % 3 == 0)y /= 3;
	if(z % 3 == 0)z /= 3;
	if(x&1)y>>=1; else x>>=1;
	return C(1LL * a * x, 1LL * y * z);
}

pnt T(LL a){
	LL x = a, y = a + 1;
	if(x&1) y >>= 1; else x >>= 1;
	return C(x, y);
}

pnt calc(int a, int b){
	if(!a || !b)return pnt(0, 0);
	pnt rt;
	if(a <= b){
		rt = T(1LL * a * a);
		if(a == b)return rt;
		rt = rt + C(1LL * a * (a + 1) / 2, 1LL * (b - a));
		rt = rt + H(a, b) - H(a, a);
		return rt;
	} else {
		rt = T(1LL * b * b);
		rt = rt + H(b, a + 1) - H(b, b + 1);
		rt = rt - C(1LL * b * (b - 1) / 2, 1LL * (a - b));
		return rt;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T, a, b, c, d;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d\n",&a, &b, &c, &d);
		pnt tp = calc(c, d) + calc(a-1, b-1) - calc(a-1, d) - calc(c, b-1);
		if(tp.x==0 && tp.y<tt)printf("%I64d\n",tp.y);
		else printf("...%010I64d\n",tp.y%tt);
	}
	return 0;
}