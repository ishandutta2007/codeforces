#include<cstdio>

char in[200010];

int main()
{
	gets(in);
	
	int cmd = 0;
	for(int i=0;in[i];i++){
		if(in[i]==' '){
			if(cmd==1){
				cmd = 0;
				printf(">\n");
			}else if(cmd==2){
				printf(" ");
			}
		}else if(in[i]=='"'){
			if(cmd==0){
				cmd = 2;
				printf("<");
			}else{
				cmd = 0;
				printf(">\n");
			}
		}else{
			if(cmd==0){
				cmd = 1;
				printf("<%c", in[i]);
			}else printf("%c", in[i]);
		}
	}
	if(cmd) printf(">\n");
	return 0;
}