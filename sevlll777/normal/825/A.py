n = int(input())
s = list(input().split('0'))
t = ''
for i in s:
    t += str(len(i))
print(t)