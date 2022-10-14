s = list(bin(int(input())))
turn = 0
ans = []
while '0' in s[2:]:
    if turn % 2 == 0:
        cnt = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '0':
                s[i] = '1'
                cnt += 1
            else:
                break
        ans.append(cnt)
    else:
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '1':
                s[i] = '0'
            else:
                s[i] = '1'
                break
    turn += 1
print(turn)
print(*ans)