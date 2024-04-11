#include <cstdio>
char get_inv(char dir){
	if(dir=='l'){
		return 'r';
	}
	else if(dir=='r'){
		return 'l';
	}
	else if(dir=='u'){
		return 'd';
	}
	else{
		return 'u';
	}
}
void move_if_no_empty(char dir){
	putchar(dir);
	putchar('s');
	putchar(get_inv(dir));
	putchar('t');
}
void move_if_0(char dir){
	putchar(dir);
	putchar(get_inv(dir));
	putchar('t');
}
void move_if_1(char dir){
	putchar(dir);
	putchar(get_inv(dir));
	putchar('s');
	putchar('t');
}
void make_copy(char dir){
	putchar(dir);
	putchar('1');
	putchar('0');
	putchar(get_inv(dir));
	putchar('t');
}
void move_all_long(char dir){
	for(int i=0;i<70;i++){
		move_if_no_empty(dir);
	}
}
void move_all_medium(char dir){
	for(int i=0;i<35;i++){
		move_if_no_empty(dir);
	}
}
void move_all_short(char dir){
	for(int i=0;i<8;i++){
		move_if_no_empty(dir);
	}
}
void print_zero(char dir){
	for(int i=0;i<34;i++){
		putchar('0');
		putchar(dir);
	}
	putchar(get_inv(dir));
}
int main(){
	move_all_medium('l');
	print_zero('l');
	move_all_long('r');
	putchar('l'),putchar('u');
	move_all_medium('l');
	print_zero('l');
	move_all_long('r');
	putchar('l'),putchar('d'),putchar('d');
	print_zero('l');
	move_all_medium('r');
	putchar('l'),putchar('u'),putchar('u');
	for(int i=0;i<32;i++){
		if(i>0){
			make_copy('l'),make_copy('d');
			putchar('u'),putchar('r'),putchar('r');
			make_copy('u'),make_copy('l'),make_copy('l'),make_copy('l');
			putchar('u'),putchar('u');
		}
		for(int j=0;j<8;j++){
			make_copy('r');
			putchar('l'),putchar('d');
			make_copy('r');
			putchar('l'),putchar('d');
			make_copy('r');
			putchar('u'),putchar('u');
			for(int k=0;k<3;k++){
				if((j>>k)&1){
					move_if_1('d');
				}
				else{
					move_if_0('d');
				}
			}
			int num=__builtin_popcount(j);
			printf("%dr%d",num&1,num>=2);
			putchar('l');
			move_all_short('u');
			putchar('d'),putchar('l');
		}
		putchar('r'),putchar('d'),putchar('d'),putchar('d');
	}
	putchar('d');
	putchar('\n');
	return 0;
}