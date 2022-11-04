A = [0] * 255
A[ord('0')]=1
A[ord('4')]=1
A[ord('6')]=1
A[ord('8')]=2
A[ord('9')]=1
A[ord('A')]=1
A[ord('B')]=2
A[ord('D')]=1
print sum(map(lambda x: A[ord(x)], hex(int(raw_input()))[2:].upper()))