
#include<cstdio>
char a[3],b[3],c,d,x,y;
int main(){
    gets(a);						//    		a8
    gets(b);						//    		h1
    x=a[0]-b[0];					//    		a-h = -7
    y=a[1]-b[1];					//  d  		8-1 = 7
    c=((x<0)?x=-x,'R':'L');				//0'R','L'
    d=((y<0)?y=-y,'U':'D');				//0'U','D'
    printf("%d",x>y?x:y);				//x,y
    while(x|y){						//xy
        puts("");
        if(x)x--,putchar(c);			        //
        if(y)y--,putchar(d);			        //
    }
    return 0;
}