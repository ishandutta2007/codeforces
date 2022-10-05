from sys import exit
n, m = map(int,input().split())
mas = list(map(int, input().split()))
pos = n
terns = []
for i in mas:
    if pos < i:
        print(-1)
        exit()
    terns.append(pos-i+1)
    pos -= 1
pos = 0
for i in range(m-1,-1,-1):
    if terns[i] > pos:
        terns[i] = pos + 1
        pos += mas[i]
    else:
        print(*terns)
        exit()
if pos < n:
    print(-1)
else:
    print(*terns)