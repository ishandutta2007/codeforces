from collections import deque
n=int(input())
s=input()
a=deque()
if n%2==1:
    for i in range(n):
        if i%2==0:
            a.append(s[i])
        else:
            a.appendleft(s[i])
else:
    for i in range(n):
        if i%2==1:
            a.append(s[i])
        else:
            a.appendleft(s[i])      
a=list(a)
print(''.join(a))