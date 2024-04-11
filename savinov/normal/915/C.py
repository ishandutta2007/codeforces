from collections import Counter

a = Counter(raw_input())
b = raw_input()

def largest(counter):
    res = ""
    for i in range(9, -1, -1):
        res += str(i) * counter[str(i)]
    return res

def find(counter, b, first=False):
    if b == "":
        r = "" if sum(counter.values()) == 0 else None
        return r
    
    res = None
    if counter[b[0]] > 0:
        r = find(counter - Counter([b[0]]), b[1:])
        if r != None:
            r = b[0] + r
            if res == None or r > res:
                res = r
   
    for x in counter:
        if first and x == 0:
            continue
        if counter[x] > 0:
            r = x + largest(counter - Counter([x]))
            if int(r) <= int(b) and (res == None or r > res):
                res = r
    return res

print(find(a, b, True))