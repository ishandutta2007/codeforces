cnt = 0
i = 1
k = int(input())
while cnt < k:
    i += 9
    if sum(list(map(int, str(i)))) == 10:
        cnt += 1
print(i)