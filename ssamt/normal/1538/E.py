def count(s, find):
    answer = 0
    for i in range(len(s)-len(find)+1):
        if s[i:i+len(find)] == find:
            answer += 1
    return answer

find = 'haha'
t = int(input())
for i in range(t):
    n = int(input())
    d = dict()
    for j in range(n):
        code = input().split()
        if len(code) == 3:
            d[code[0]] = [count(code[2], find), code[2][:3], code[2][-3:]]
        else:
            a = code[2]
            b = code[4]
            new = [d[a][0]+d[b][0]+count(d[a][2]+d[b][1], find)]
            new.append((d[a][1]+d[b][1])[:3])
            new.append((d[a][2]+d[b][2])[-3:])
            d[code[0]] = new
    print(d[code[0]][0])