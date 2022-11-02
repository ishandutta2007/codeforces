n = gets.to_i
p = gets.split.map { |x| x.to_i }

cnt = 0
flag = false
n.times do |i|
	if p[i] == i
		cnt += 1
	elsif p[p[i]] == i
		flag = true
	end
end

if cnt == n
	puts cnt
elsif flag
	puts cnt + 2
else
	puts cnt + 1
end