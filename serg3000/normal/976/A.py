n = int(input())
s = input()
c = 0;
for i  in range(n):
    if s[i] == '0':
        c += 1;
if int(s[0]) != 0:
    print(1, end= '')
print('0' * c)