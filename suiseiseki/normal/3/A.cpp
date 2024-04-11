#include <cstdio>
char qu[5];
int sx,sy;
int ex,ey;
void dfs(int sx,int sy){
	if(sx==ex&&sy==ey){
		return;
	}
	else if(sx==ex){
		if(sy<ey){
			for(int i=sy;i<ey;i++){
				puts("U");
			}
		}
		else{
			for(int i=sy;i>ey;i--){
				puts("D");
			}
		}
		return;
	}
	else if(sy==ey){
		if(sx<ex){
			for(int i=sx;i<ex;i++){
				puts("R");
			}
		}
		else{
			for(int i=sx;i>ex;i--){
				puts("L");
			}
		}
		return;
	}
	else if(ex<sx&&ey<sy){
		puts("LD");
		dfs(sx-1,sy-1);
	}
	else if(ex<sx&&ey>sy){
		puts("LU");
		dfs(sx-1,sy+1);
	}
	else if(ex>sx&&ey<sy){
		puts("RD");
		dfs(sx+1,sy-1); 
	}
	else{
		puts("RU");
		dfs(sx+1,sy+1);
	}
}
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int ab(int a){
	return a<0?-a:a;
}
int main(){
	scanf("%s",qu);
	sx=qu[0]-'a'+1;
	sy=qu[1]-'0';
	scanf("%s",qu);
	ex=qu[0]-'a'+1;
	ey=qu[1]-'0';
	printf("%d\n",mx(ab(sx-ex),ab(sy-ey)));
	dfs(sx,sy);
	return 0;
}